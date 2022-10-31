#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,sb,f[3050][3050],lst,l,r,pos,g[3050],it;

string s1[3050],s2[3050];
string r1="0",r2="0";

int main() {
	ios::sync_with_stdio(0);
	cin>>n;
	for(i=1;i<=n;i++)cin>>s1[i];
	for(i=1;i<=n;i++)cin>>s2[i];
	for(i=1;i<=n;i++){
		int l1,r1;
		m=s1[i].size();
		s1[i]="0"+s1[i];
		s2[i]="0"+s2[i];
		for(j=1;j<=m;j++){
			if(s1[i][j]!=s2[i][j]){
				if(!lst){
					lst=i;l=j-1;r=m-j;pos=j;
				}
				else{
					l1=r1=-1;
					while(l1<l){
						l1++;if(j-l1<0){l1--;break;}
						if(s1[i][j-l1]!=s1[lst][pos-l1]||s2[i][j-l1]!=s2[lst][pos-l1]){l1--;break;}
					}
					while(r1<r){
						r1++;if(j+r1<0){r1--;break;}
						if(s1[i][j+r1]!=s1[lst][pos+r1]||s2[i][j+r1]!=s2[lst][pos+r1]){r1--;break;}
					}
					l=l1;r=r1;
				}
				break;
			}
		}
	}
	if(!lst){
		cout<<"YES\nsb\nsb\n";return 0;
	}
	for(i=pos-l;i<=pos+r;i++){
		r1+=s1[lst][i];
		r2+=s2[lst][i];
	}
	//cout<<r1<<endl<<r2<<endl;
	j=0;
	for(i=2;i<=r1.size()-1;i++){
		while(j&&r1[i]!=r1[j+1])j=g[j];
		if(r1[j+1]==r1[i])j++;
		g[i]=j;
	}
	for(i=1;i<=n;i++){
		it=0;
		for(j=1;j<s1[i].size();j++){
			while(it&&s1[i][j]!=r1[it+1])it=g[it];
			if(s1[i][j]==r1[it+1])it++;
			if(it==r1.size()-1){
				while(it){
					s1[i][j]=r2[it];j--;it--;
				}
				break;
			}
		}
		//cout<<s1[i]<<endl<<s2[i]<<endl;
		if(s1[i]!=s2[i]){
			cout<<"NO";return 0;
		}
	}
	cout<<"YES\n"<<r1.substr(1)<<'\n'<<r2.substr(1);
}