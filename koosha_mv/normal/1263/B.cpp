#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i<b;i+=2)
#define ll long long
int t,n,tagh,mark[10],p;
string s[100009];
int main(){
	cin>>t;
	f(sal,0,t){
		cin>>n;tagh=0;
		f(i,0,n){
			cin>>s[i];
		}
		f(i,0,n){
			f(j,i+1,n){
				if(s[i]==s[j]){
					tagh++;
					f(l,0,10) mark[l]=0;
					f(k,0,n){
						mark[int(s[k][0])-'0']=1;
					}
					f(k,0,10){if(mark[k]==0) p=k;}
					s[j][0]=char(p+'0');
				}
			}
		}
		cout<<tagh<<endl;
		f(i,0,n){cout<<s[i]<<endl;}
	}
}