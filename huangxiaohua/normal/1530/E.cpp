#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[30],st,mn,sum1,sum2,j2,j3;
string s;
char c;
int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		memset(a,0,sizeof(a));
		k=0;st=0;mn=1145141919;
		cin>>s;
		for(auto i:s){
			a[i-'a'+1]++;
		}
		for(i=1;i<=26;i++){
			if(a[i]){
				if(!st){st=i;}
				k++;
				mn=min(mn,a[i]);
			}
		}
		
		if(k==1){
			for(i=1;i<=a[st];i++){
				c='a'+st-1;
				cout<<c;
			}
			cout<<endl;continue;
		}
		
		if(mn==1){
			for(i=1;i<=26;i++){
				if(a[i]==1){
					c='a'+i-1;
					cout<<c;a[i]=0;break;
				}
			}
			
			for(i=1;i<=26;i++){
				for(j=1;j<=a[i];j++){
					c='a'+i-1;
					cout<<c;
				}
			}
			cout<<endl;continue;
		}
		
		j=0;
		for(i=1;i<=26;i++){
			if(a[i]){j=i;break;}
		}
		
		sum1=a[j];
		sum2=0;
		for(i=j+1;i<=26;i++){
			sum2+=a[i];
		}
		
		if(sum2+2>=sum1){
			c='a'+j-1;
			cout<<c<<c;a[j]-=2;
			for(i=j+1;i<=26;i++){
				for(k=1;k<=a[i];k++){
					c='a'+i-1;cout<<c;
					
					if(a[j]){
						c='a'+j-1;cout<<c;a[j]--;
					}
				}
			}
			cout<<endl;continue;
		}
		else{
			if(k==2){
				c='a'+j-1;cout<<c;a[j]--;
				for(i=j+1;;i++){
					if(a[i]){
						for(k=1;k<=a[i];k++){
							c='a'+i-1;cout<<c;
						}
						break;
					}
				}
				for(i=1;i<=a[j];i++){
					c='a'+j-1;cout<<c;
				}
				cout<<endl;continue;
			}
			else{
				c='a'+j-1;cout<<c;a[j]--;
				for(i=j+1;;i++){
					if(a[i]){
						c='a'+i-1;cout<<c;a[i]--;
						for(k=1;k<=a[j];k++){
							c='a'+j-1;cout<<c;
						}
						a[j]=0;
						j=i;
						break;
					}
				}
				for(i=j+1;;i++){
					if(a[i]){
						c='a'+i-1;cout<<c;a[i]--;
						break;
					}
				}
				
				for(i=1;i<=26;i++){
					for(k=1;k<=a[i];k++){
						c='a'+i-1;cout<<c;
					}
				}
				cout<<endl;
			}
		}
	}
}