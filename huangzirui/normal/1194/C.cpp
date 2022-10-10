#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pr printf
#define P push
#define PB push_back
#define F front
#define T top
#define MP make_pair
#define Fi first
#define Se second
using namespace std;
inline long long gcd(long long a,long long b){return b==0?a:gcd(b,a%b);}
inline long long lcm(long long a,long long b){return a/gcd(a,b)*b;}
inline void read(long long &x){
	char ch;
	do ch=getchar();while(ch<48||ch>57);
	x=0;while(ch<=57&&ch>=48){x=x*10+ch-48;ch=getchar();}
}
inline void read(int &x){
	char ch;
	do ch=getchar();while(ch<48||ch>57);
	x=0;while(ch<=57&&ch>=48){x=x*10+ch-48;ch=getchar();}
}
int i,j,k,n,m;
string start_,end_,help_;
int need[27],Can[27];
int main(){
	int t;
	cin>>t;
	while(t--){
		memset(need,0,sizeof(need));
		memset(Can,0,sizeof(Can));
		cin>>start_>>end_>>help_;
		int len1=start_.size(),len2=end_.size(),len3=help_.size();
		k=0;
		int isno=0;
		for(i=0;i<len1;i++){
			int can=0;
			for(j=k;j<len2;j++)
				if(start_[i]==end_[j]){
					k=j+1;can=1;break;
				}else need[end_[j]-'a'+1]++;
			if(!can){
				cout<<"NO"<<endl;
				isno=1;
				break;
			}
		}
		for(i=k;i<len2;i++)
			need[end_[i]-'a'+1]++;
		if(isno)continue;
		for(i=0;i<len3;i++)
			Can[help_[i]-'a'+1]++;
		for(i=1;i<=26;i++){
			if(need[i]>Can[i]){
				cout<<"NO"<<endl;
				isno=1;
				break;
			}
		}
		if(isno)continue;
		cout<<"YES"<<endl;
	}
	return 0;
}