#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define Gett(x,y) scanf("%d%d",&x,&y);
#define gett(x) scanf("%d",&x);																																														
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define S second
#define F first
#define mp make_pair
const int N=3e5+20;
int t,n,sz,mx,ans1,ans2,a1,a2;
string s,ans,s1,s2;
int check(string s){
	string rev="",str=s;
    int m=s.size(),longestPalindromicPrefix=1;
    if(m==0 || m==1)    longestPalindromicPrefix=m; 
    for(int i=m-1;i>=0;i--)
        rev+=s[i];
    s+='#';
    s+=rev;
    int n=s.size(),z[n+4],l=0,r=0;
    for(int i=1;i<n;i++){
        if(i>r){
            l=r=i;
            while(r<n && s[r-l]==s[r])
                r++;
            z[i]=r-l,r--;
        }
        else{
            int k=i-l;
            if(z[k]<r-i+1)
                z[i]=z[k];
            else{
                l=i;
                while(r<n && s[r-l]==s[r])
                    r++;
                z[i]=r-l,r--;
            }
        }
    }

    for(int i=m+1;i<n;i++){
        if(2*z[i]>=2*m-i && z[i]>longestPalindromicPrefix)
            longestPalindromicPrefix=z[i];
    }
    return longestPalindromicPrefix;
}
int main(){
	cin>>t;
	f(q,0,t){
		cin>>s;
		s1="";
		s2="";
		n=s.size();
		ans1=-1;
		f(i,0,n/2){
			if(s[i]==s[n-i-1])
				ans1=i;
			else
				break;
		}
 		f(i,ans1+1,n-ans1-1)
			s1+=s[i];
		f_(i,n-ans1-1-1,ans1+1)
			s2+=s[i];
		a1=check(s1);
		a2=check(s2);
		if(a1>a2){
			f(i,0,ans1+1)
				cout<<s[i];
			f(i,ans1+1,ans1+1+a1)
				cout<<s[i];
			f_(i,ans1,0)
				cout<<s[i];
		}
		else{
			f(i,0,ans1+1)
				cout<<s[i];
			f(i,n-ans1-a2-1,n-ans1-1)
				cout<<s[i];
			f_(i,ans1,0)
				cout<<s[i];
		}
		cout<<endl;
	}
}