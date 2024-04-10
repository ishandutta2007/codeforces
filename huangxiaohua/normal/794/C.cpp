#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,l,r,ty,x,y;
string s1,s2;
char res[2005000];
vector<int> v;

int main() {
	//ios::sync_with_stdio(0);
	cin>>s1>>s2;
	n=s1.size();
	sort(s1.begin(),s1.end());
	sort(s2.begin(),s2.end());
	reverse(s2.begin(),s2.end());
	ty=0;
	l=1;r=n;
	while(l<=r){
		if(!ty){
			if(s1[x]<s2[y]){
				res[l]=s1[x];l++;
				x++;
			}
			else{
				for(i=r;i>=l;i-=2){
				
				}
				i+=2;
				for(;i<=r;i+=2){
					res[i]=s1[x];x++;
				}
				
				for(i=r-1;i>=l;i-=2){
				
				}
				i+=2;
				for(;i<=r-1;i+=2){
					res[i]=s2[y];y++;
				}
				break;
			}
			
		}
		else{
			if(s2[y]>s1[x]){
				res[l]=s2[y];l++;
				y++;
			}
			else{
				for(i=r;i>=l;i-=2){
				
				}
				i+=2;
				for(;i<=r;i+=2){
					res[i]=s2[y];y++;
				}
				
				for(i=r-1;i>=l;i-=2){
				
				}
				i+=2;
				for(;i<=r-1;i+=2){
					res[i]=s1[x];x++;
				}
				break;
			}
			
		}
		
		ty^=1;
	}
	cout<<res+1;
}