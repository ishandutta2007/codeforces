#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=4e5+10;
int w[N],ne[N],la[N];
int a[N],b[N],r,n,t,sw[N],fa[N],q,s1[N],dep[N],nx[N],s2[N];
void link(int x,int y){
	w[++t]=y;
	ne[t]=la[x];
	la[x]=t;
}
void dfs(int x){
	for (int y=la[x];y;y=ne[y]){
		int z=w[y];
		if (z==fa[x])continue;
		fa[z]=x;
		dep[z]=dep[x]+1;
		dfs(z);
	}
}
void go(int x){
	if (x==r)return;
	if (fa[x]!=r)go(fa[x]);
	swap(a[fa[x]],a[x]),sw[x]=1;
	nx[fa[x]]=x;
}
int main(){
	cin>>n;
	for (int i=1;i<=n;i++)scanf("%d",&a[i]),r=a[i]?r:i;
	for (int i=1;i<=n;i++)scanf("%d",&b[i]),q=b[i]?q:i;
	int tag1=0;
	if (n==200000&&a[1]==13809){
		tag1=0;
//		cout<<-1<<endl;
//		return 0;
	}
	for (int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		link(x,y);
		link(y,x);
	}
	dfs(r);
	ll ans=dep[q];
	go(q);sw[r]=1;
	int case0=0;
	for (int i=1;i<=n;i++){
		if (a[i]!=b[i]&&sw[i]){
			case0=1;
		}
	}
	// begin case0
	if (case0){
	
	int cnt1=0,cnt2=0;
	for (int x=1;x<=n;x++){
		int cnt=0;
		if (a[x]!=b[x]){
			for (int y=la[x];y;y=ne[y])
				cnt+=a[w[y]]!=b[w[y]];
			if (cnt>2){
				cout<<-1<<endl;
				return 0;
			}
			if (cnt==1)cnt1++;
			s1[x]=cnt;
			s2[x]=cnt-(a[fa[x]]!=b[fa[x]]);
			if (cnt==0)cnt1+=2;
		}
		else {
			if (sw[x]&&b[x]){
				for (int y=la[x];y;y=ne[y])
					cnt+=a[w[y]]!=b[w[y]];
				if (cnt==2&&a[fa[x]]!=b[fa[x]]){
					cnt2++;
					s1[x]=100;
					for (int y=la[x];y;y=ne[y]){
						int z=w[y];
						if (z!=fa[x]&&a[z]!=b[z]&&sw[z]){
							cnt2=100;
						}
					}
				}
			}
		}
	}
	if(cnt1==2&&cnt2==0){
		int x,y,z,X,Y,l=0;
		for (int i=1;i<=n;i++){
			if (s1[i]==1)y=x,x=i;
			if (a[i]!=b[i]&&(l==0||dep[i]<dep[l]))l=i;
		}
		if (sw[x]&&sw[y]){
			if (dep[x]>dep[y])swap(x,y);
			X=x,z=Y=nx[y];
			vector<int> a0;
			while (y!=x)a0.push_back(y),y=fa[y];
			a0.push_back(x);
			reverse(a0.begin(),a0.end());
			int sum=0,sum2=0;
			for (int i=0;i<a0.size();i++)sum+=sw[a0[i]];
			int k=0;
			for (int i=0;i<a0.size();i++)
				if (a[a0[i]]==b[a0[0]]){
					k=i;
					break;
				}
			for (int i=0;i<a0.size();i++)
				if (a[a0[(i+k)%a0.size()]]!=b[a0[i]]){
					cout<<-1<<endl;
					return 0;
				}
			ll ans1=(a0.size()+1)*k,ans2=(a0.size()+1)*(a0.size()-k)-2*sum;
			if (tag1){
				cout<<ans1<<' '<<ans2<<' '<<sum<<endl;
			}
			if (tag1){
				cout<<1<<endl;
			}
			cout<<min(X,Y)<<' '<<max(X,Y)<<' ';
			cout<<ans+sum2+min(ans1,ans2)<<endl;
			return 0;	
		}
		if (sw[x]+sw[y]==1){
			if (sw[x])swap(x,y);
			X=x,Y=nx[y];
			vector<int> a1,a2,a0;
			for (;x!=l;x=fa[x])a1.push_back(x);a1.push_back(l);
			for (;y!=l;y=fa[y])a2.push_back(y);
			a0=a1;
			while (a2.size())a0.push_back(a2.back()),a2.pop_back();
			int sum=0,sum2=0;
			for (int i=0;i<a0.size();i++)sum+=sw[a0[i]];
			int k=0;
			for (int i=0;i<a0.size();i++)
				if (a[a0[i]]==b[a0[0]]){
					k=i;
					break;
				}
			for (int i=0;i<a0.size();i++)
				if (a[a0[(i+k)%a0.size()]]!=b[a0[i]]){
					cout<<-1<<endl;
					return 0;
				}
			ll ans1=(a0.size()+1)*k,ans2=(a0.size()+1)*(a0.size()-k)-2*sum;
			if (tag1){
				cout<<ans1<<' '<<ans2<<' '<<sum<<endl;
			}
			if (tag1){
				cout<<2<<endl;
			}
			cout<<min(X,Y)<<' '<<max(X,Y)<<' ';
			cout<<ans+sum2+min(ans1,ans2)<<endl;
			return 0;			
		}
		cout<<-1<<endl;
		return 0;
	}
	if (cnt1==4&&cnt2==1){
		int x,y,u,X,Y,l=0;
		for (int i=1;i<=n;i++)
			if (s1[i]==100)u=i;
		for (int i=1;i<=n;i++){
			if ((s1[i]==1&&!sw[i]||s1[i]==0)&&s2[i]==0&&a[i]!=b[i])y=x,x=i;
			if (a[i]!=b[i]&&(l==0||dep[i]<dep[l]))l=i;			
		}
//		for (int y=la[u];y;y=ne[y]){
//			if (a[w[y]]!=b[w[y]]){
//				if (s1[w[y]]!=1||sw[w[y]]&&w[y]!=fa[u]){
//					cout<<-1<<endl;
//					return 0;
//				}
//			}
//		}
		if (fa[l]==u){
			cout<<-1<<endl;
			return 0;
		} 
		static int tag0[N];
		X=x,Y=y;
		assert(sw[l]);
		assert(a[l]!=b[l]);
		int x0=x,y0=y;
		while (x0!=l&&x0!=u){
			assert(a[x0]!=b[x0]);
			assert(sw[x0]==0);
			tag0[x0]=1;
			x0=fa[x0];
		}
		while (y0!=l&&y0!=u){
			assert(a[y0]!=b[y0]);
			assert(sw[y0]==0);
			tag0[y0]=1;
			y0=fa[y0];
		}
		assert(x0!=y0);
		int u0=fa[u];
		assert(sw[u]&&a[u]==b[u]);
		while (u0!=l){
			assert(sw[u0]);
			assert(a[u0]!=b[u0]);
			tag0[u0]=1;
			u0=fa[u0];
		}tag0[l]=1;
		for (int i=1;i<=n;i++){
			if (tag0[i]!=(a[i]!=b[i])){
				cout<<-1<<endl;
				return 0;
			}
			assert(tag0[i]==(a[i]!=b[i]));
		}
//		if (tag1==1){
//			cout<<X<<' '<<Y<<endl;
//		}
		vector<int> a1,a2,a0;
		int tag=0;
		for (;x!=l;x=fa[x])a1.push_back(x),tag|=1*(x==u);
		for (;y!=l;y=fa[y])a2.push_back(y),tag|=2*(y==u);
		if (tag==1)swap(a1,a2);
		a0=a1;a0.push_back(l);
		while (a2.size()){
			if (a2.back()!=u)a0.push_back(a2.back());
			a2.pop_back();
		}
		int sum=0,sum2=0;
		for (int i=0;i<a0.size();i++)sum+=sw[a0[i]];
		int k=0;
		for (int i=0;i<a0.size();i++)
			if (a[a0[i]]==b[a0[0]]){
				k=i;
				break;
			}
		for (int i=0;i<a0.size();i++)
			if (a[a0[(i+k)%a0.size()]]!=b[a0[i]]){
				cout<<-1<<endl;
				return 0;
			}
		ll ans1=(a0.size()+1)*k,ans2=(a0.size()+1)*(a0.size()-k)-2*sum;
			if (tag1){
				cout<<ans1<<' '<<ans2<<' '<<sum<<endl;
			}
			if (tag1){
				cout<<l<<' '<<u<<' '<<dep[l]<<' '<<dep[u]<<' '<<dep[X]<<' '<<dep[Y]<<' '<<sw[u]<<' '<<nx[u]<<endl;
				cout<<3<<endl;
			}
		cout<<min(X,Y)<<' '<<max(X,Y)<<' ';
		cout<<ans+sum2+min(ans1,ans2)<<endl;
		return 0;			
	}
	cout<<-1<<endl;
	return 0;
	
		
	}
	
	// end case0
	int cnt1=0,cnt2=0,cnt3=0,cnt4=0,cnt5=0;
	for (int x=1;x<=n;x++){
		int cnt=0;
		if (a[x]==b[x]){
			for (int y=la[x];y;y=ne[y])
				if (fa[x]!=w[y])cnt+=a[w[y]]!=b[w[y]];
			if (cnt==2)cnt1++;
			if (cnt==1)cnt3++;
			if (cnt>2)cnt4++;
		}
		else {
			cnt5++;
			for (int y=la[x];y;y=ne[y])
				if (fa[x]!=w[y])cnt+=a[w[y]]!=b[w[y]];
			if (cnt==0)cnt2++;
			if (cnt>1)cnt4++;
		}
		s1[x]=cnt;
	}
	if (!cnt5){
		cout<<0<<' '<<ans<<endl;
		return 0;
	}
	if (cnt4){
		cout<<-1<<endl;
		return 0;
	}
	if (cnt1==1&&cnt2==2){
		int x,y,u,v,X,Y,z;
		for (int i=1;i<=n;i++){
			if (a[i]!=b[i]&&a[fa[i]]==b[fa[i]])v=u,u=i;
			if (a[i]!=b[i]&&s1[i]==0)y=x,x=i;
		}
		X=x,Y=y;z=fa[u];assert(z==fa[v]);
		if (sw[v])swap(u,v);
		vector<int> a1,a2,a0;
		for (;x!=u&&x!=v;x=fa[x])a1.push_back(x);a1.push_back(x);
		for (;y!=u&&y!=v;y=fa[y])a2.push_back(y);a2.push_back(y);
		if (a2.back()==u)swap(a1,a2);
		a0=a1;
		while (a2.size())a0.push_back(a2.back()),a2.pop_back();
		int sum=0,sum2=0;
		while (!sw[z]&&z!=r)sum2+=2,z=fa[z];
		for (int i=0;i<a0.size();i++)sum+=sw[a0[i]];
		int k=0;
		for (int i=0;i<a0.size();i++)
			if (a[a0[i]]==b[a0[0]]){
				k=i;
				break;
			}
		for (int i=0;i<a0.size();i++)
			if (a[a0[(i+k)%a0.size()]]!=b[a0[i]]){
				cout<<-1<<endl;
				return 0;
			}
		ll ans1=(a0.size()+1)*k-2*sum,ans2=(a0.size()+1)*(a0.size()-k);
			if (tag1){
				cout<<4<<endl;
			}
		cout<<min(X,Y)<<' '<<max(X,Y)<<' ';
		cout<<ans+sum2+min(ans1,ans2)<<endl;
		return 0;
	}
	if (cnt3==1&&cnt2==1){
		int x,y,z,X,Y;
		for (int i=1;i<=n;i++){
			if (a[i]!=b[i]&&a[fa[i]]==b[fa[i]])x=i;
			if (a[i]!=b[i]&&s1[i]==0)y=i;
		}
		X=fa[x];
		Y=y;
		z=fa[x];
		vector<int> a0;
		while (y!=x)a0.push_back(y),y=fa[y];
		a0.push_back(x);
		reverse(a0.begin(),a0.end());
		int sum=0,sum2=0;
		while (!sw[z]&&z!=r)sum2+=2,z=fa[z];
		for (int i=0;i<a0.size();i++)sum+=sw[a0[i]];
		int k=0;
		for (int i=0;i<a0.size();i++)
			if (a[a0[i]]==b[a0[0]]){
				k=i;
				break;
			}
		for (int i=0;i<a0.size();i++)
			if (a[a0[(i+k)%a0.size()]]!=b[a0[i]]){
				cout<<-1<<endl;
				return 0;
			}
		ll ans1=(a0.size()+1)*k-2*sum,ans2=(a0.size()+1)*(a0.size()-k);
			if (tag1){
				cout<<5<<endl;
			}
		cout<<min(X,Y)<<' '<<max(X,Y)<<' ';
		cout<<ans+sum2+min(ans1,ans2)<<endl;
		return 0;	
	}
	cout<<-1<<endl;
}