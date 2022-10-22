#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
int kh[200009],sk=0;
int main(){
	int q,n,k;
	string s,s1;
	cin>>q;
	f(po,0,q){
		s1="";
		cin>>n>>k>>s;
		f(i,0,n/2-k+1) s1+='(';
		f(i,0,n/2-k+1) s1+=')';
		f(i,0,n-(2*(n/2-k+1))) {
			if(i%2==0)
				s1+='(';
			else
				s1+=')';
		}
		sk=0;
		f(i,0,n){
			if(s[i]!=s1[i]){
				f(j,i+1,n){
					if(s[j]==s1[i]){
						kh[sk]=i,kh[sk+1]=j;
						sk+=2;
						swap(s[i],s[j]);
						break;
					}
				}
			}
		}
		cout<<sk/2<<endl;
		f(i,0,sk/2){
			cout<<kh[i*2]+1<<" "<<kh[i*2+1]+1<<endl;
		}

	}
}