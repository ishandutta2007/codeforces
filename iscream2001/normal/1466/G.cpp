#include<bits/stdc++.h>
#define LL long long
#define ull unsigned long long
using namespace std;
const int N=1e5+10;
const LL P=1e9+7;
const ull sed=31;
LL gcd(LL a,LL b) {
    return b?gcd(b,a%b):a;
}
LL qpow(LL x,LL y){
	LL re=1;
	while(y){
		if(y&1) re=re*x%P;
		x=x*x%P;y>>=1;
	}
	return re;
}

int n,Q,Ls,K,Lt;
LL bin[1000005];
char s[110],t[100005];
LL hhh[100005][26];
ull bas[1000005];
ull S[110];
ull geths(int l,int r){
	return S[r]-S[l-1]*bas[r-l+1];
}
char tt[1000005];
ull T[1000005];
ull getht(int l,int r){
	return T[r]-T[l-1]*bas[r-l+1];
}
vector<int> V,A[100005];
LL ask(int lv){
	if(lv>K) return 0;
	if(A[lv].size()==1){
		return (hhh[K][tt[A[lv][0]]-'a']-hhh[lv-1][tt[A[lv][0]]-'a'])*bin[K]%P;
	}
	LL res=0;
	A[lv+1].clear();
	bool flag=0;
	for(int i=0;i<A[lv].size();++i){
		if(i&1){
			if(tt[A[lv][i]]!=t[lv]) {
				flag=1;break;
			}
		}
		else{
			A[lv+1].push_back(A[lv][i]);
		}
	}
	if(flag==0){
		if(A[lv+1].size()>0) res+=ask(lv+1);
		else res+=bin[K-lv];
	}
	A[lv+1].clear();
	flag=0;
	for(int i=0;i<A[lv].size();++i){
		if(!(i&1)){
			if(tt[A[lv][i]]!=t[lv]) {
				flag=1;break;
			}
		}
		else{
			A[lv+1].push_back(A[lv][i]);
		}
	}
	if(flag==0){
		if(A[lv+1].size()>0) res+=ask(lv+1);
		else res+=bin[K-lv];
	}
	res=res%P;
	return res;
}
int main(){
	bin[0]=1;for(int i=1;i<=1000000;++i){
		bin[i]=bin[i-1]+bin[i-1];
		if(bin[i]>=P)bin[i]-=P;
	}
	bas[0]=1;
	for(int i=1;i<=1000000;++i) bas[i]=bas[i-1]*sed;
	scanf("%d%d",&n,&Q);
	scanf("%s%s",s+1,t+1);Ls=strlen(s+1); 
	S[0]=0;for(int i=1;i<=Ls;++i){
		S[i]=S[i-1]*sed+s[i]-'a'+1;
	}
	for(int i=1;i<=n;++i){
		for(int j=0;j<26;++j) hhh[i][j]=hhh[i-1][j];
		int j=t[i]-'a';
		hhh[i][j]=(hhh[i][j]+qpow(bin[i],P-2))%P;
	}
	LL ans;
	int j,k,fff;
	while(Q--){
		scanf("%d%s",&K,tt+1);Lt=strlen(tt+1);
		T[0]=0;for(int i=1;i<=Lt;++i){
			T[i]=T[i-1]*sed+tt[i]-'a'+1;
		}
		ans=0;
		if(Lt<=Ls){
			for(int i=1;i<=Ls-Lt+1;++i){
				if(geths(i,i+Lt-1)==getht(1,Lt)){
					ans+=bin[K];
				}
			}
		}
		for(int i=0;i<=Ls;++i){
			V.clear();
			if(i>Lt) break;
			if(geths(Ls-i+1,Ls)!=getht(1,i)) continue;
			if(i==Lt){
				//ans+=bin[K];
				continue;
			}
			j=i+1;fff=0;
			while(j<=Lt){
				V.push_back(j);
				k=min(Lt,j+Ls);
				j++;
				if(j>k) continue;
				if(geths(1,k-j+1)!=getht(j,k)){
					fff=1;break;
				}
				j=k+1;
			}
			if(fff==0){
				A[1]=V; 
				//cout<<"? "<<i<<" "<<V.size()<<" "<<V[0]<<endl;
				ans+=ask(1);
			}
		}
		ans=(ans%P+P)%P;
		printf("%lld\n",ans);
	}
	return 0;
}