#include<bits/stdc++.h>
using namespace std;
typedef vector<int> poly;
const int N=131072,P=998244353,g=3,I=86583718;
int pow(int a,int b){
	int ans=1;
	while(b){
		if(b&1){
			ans=1ll*ans*a%P;
		}
		a=1ll*a*a%P;
		b>>=1;
	}
	return ans;
}
poly bit_reverse_copy(poly a){
	int n=a.size();
	for(int i=1,j=0,k;i<n;++i){
		for(k=n>>1;j>=k;j-=k,k>>=1);
		j+=k;
		if(i<j){
			swap(a[i],a[j]);
		}
	}
	return a;
}
poly NTT(poly a,int opt){
	int n=a.size();
	a=bit_reverse_copy(a);
	for(int l=2;l<=n;l<<=1){
		int omega=pow(g,(P-1)/l);
		if(opt==-1){
			omega=pow(omega,P-2);
		}
		for(int i=0;i<n;i+=l){
			int u,v,w=1;
			for(int j=i;j<i+(l>>1);++j){
				u=a[j];
				v=1ll*w*a[j+(l>>1)]%P;
				a[j]=(u+v)%P;
				a[j+(l>>1)]=(u-v+P)%P;
				w=1ll*w*omega%P;
			}
		}
	}
	if(opt==-1){
		int inv=pow(n,P-2);
		for(int i=0;i<n;++i){
			a[i]=1ll*a[i]*inv%P;
		}
	}
	return a;
}
poly integral(poly a){
	int n=a.size();
	for(int i=n-1;i>=1;--i){
		a[i]=1ll*a[i-1]*pow(i,P-2)%P;
	}
	a[0]=0;
	return a;
}
poly derivative(poly a){
	int n=a.size();
	for(int i=0;i<n-1;++i){
		a[i]=1ll*a[i+1]*(i+1)%P;
	}
	a[n-1]=0;
	return a;
}
poly inv(poly a){
	int n=a.size();
	poly b{pow(a[0],P-2)};
	for(int l=2;l<=n;l<<=1){
		poly t(l<<1);
		for(int i=0;i<l;++i){
			t[i]=a[i];
		}
		b.resize(l<<1);
		t=NTT(t,1);
		b=NTT(b,1);
		for(int i=0;i<(l<<1);++i){
			b[i]=((2-1ll*t[i]*b[i])%P*b[i]%P+P)%P;
		}
		b=NTT(b,-1);
		b.resize(l);
	}
	return b;
}
poly ln(poly a){
	int n=a.size();
	poly b=inv(a);
	a=derivative(a);
	a.resize(n<<1);
	b.resize(n<<1);
	a=NTT(a,1);
	b=NTT(b,1);
	for(int i=0;i<(n<<1);++i){
		a[i]=1ll*a[i]*b[i]%P;
	}
	a=NTT(a,-1);
	a.resize(n);
	return integral(a);
}
poly exp(poly a){
	int n=a.size();
	poly b{1};
	for(int l=2;l<=n;l<<=1){
		b.resize(l);
		poly t=ln(b);
		for(int i=0;i<l;++i){
			t[i]=(a[i]-t[i]+P)%P;
		}
		t[0]=(t[0]+1)%P;
		t.resize(l<<1);
		b.resize(l<<1);
		t=NTT(t,1);
		b=NTT(b,1);
		for(int i=0;i<(l<<1);++i){
			b[i]=1ll*b[i]*t[i]%P;
		}
		b=NTT(b,-1);
		b.resize(l);
	}
	return b;
}
poly sqrt(poly a){
	int n=a.size();
	poly b{1};
	int inv2=pow(2,P-2);
	for(int l=2;l<=n;l<<=1){
		b.resize(l);
		poly t=inv(b),r(l<<1);
		t.resize(l<<1);
		for(int i=0;i<l;++i){
			r[i]=a[i];
		}
		t=NTT(t,1);
		r=NTT(r,1);
		for(int i=0;i<(l<<1);++i){
			t[i]=1ll*t[i]*r[i]%P;
		}
		t=NTT(t,-1);
		for(int i=0;i<l;++i){
			b[i]=1ll*(b[i]+t[i])*inv2%P;
		}
	}
	return b;
}
poly sin(poly a){
	int n=a.size();
	for(int i=0;i<n;++i){
		a[i]=1ll*a[i]*I%P;
	}
	poly t=exp(a),ans=t;
	t=inv(t);
	int inv=pow(2*I,P-2);
	for(int i=0;i<n;++i){
		ans[i]=(1ll*(ans[i]-t[i])*inv%P+P)%P;
	}
	return ans;
}
poly cos(poly a){
	int n=a.size();
	for(int i=0;i<n;++i){
		a[i]=1ll*a[i]*I%P;
	}
	poly t=exp(a),ans=t;
	t=inv(t);
	int inv2=pow(2,P-2);
	for(int i=0;i<n;++i){
		ans[i]=1ll*(ans[i]+t[i])*inv2%P;
	}
	return ans;
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	poly a(N);
	for(int i=0;i<n;++i){
		int x;
		scanf("%d",&x);
		a[x]=P-4;
	}
	++a[0];
	a=sqrt(a);
	a[0]=(a[0]+1)%P;
	a=inv(a);
	for(int i=1;i<=m;++i){
		printf("%d\n",a[i]*2%P);
	}
	return 0;
}