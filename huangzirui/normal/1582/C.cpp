#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
int i,j,k,n,m,T;
int main(){
	cin>>T;
	while(T--){
		string S;
		cin>>n;
		cin>>S;
		char chs1,chs2='#';
		for(i=0;i<=S.size()/2;i++){
			if(S[i]!=S[n-i-1]){
				chs1=S[i];
				chs2=S[n-i-1];
				break;
			}
		}
		if(chs2=='#'){
			puts("0");
		}else{
			string tmp="";
			int ans=1e9;
			for(chs1='a';chs1<='z';chs1++){
				int L=0,R=S.size()-1,sum0=0;
//				cout<<"chs1="<<chs1<<endl;
				while(L<R){
					if(S[L]!=S[R]){
						if(S[L]==chs1)L++,sum0++;
						else if(S[R]==chs1)R--,sum0++;
						else break;
					}else L++,R--;
				}
				if(L>=R)ans=min(ans,sum0);
//				cout<<sum0<<endl;
			}
			if(ans!=1000000000)cout<<ans<<endl;
			else puts("-1");
		}
	}
	return 0;
}