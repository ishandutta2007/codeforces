#include<bits/stdc++.h>
using namespace std;
int n,k;
void work(){
	cin>>n>>k;
	if(k%4==0){
		puts("NO");
		return;
	}
	k=4-k%4;
	if(n%4==2&&k<=2){
		puts("YES");
		for(int i=2;i<=n;i+=2){
			if(i%4==0)cout<<i-1<<" "<<i<<endl;
			else cout<<k+i-2<<" "<<(k==2?i-1:i)<<endl;
		}
	}
	else if(n%4==0){
		puts("YES");
		for(int i=4;i<=n;i+=4){
			bool bol=0;
			for(int j=i-4+1;j<=i;++j){
				if(j%4!=0&&j%4!=k){
					if(bol)cout<<k+i-4<<" "<<j<<endl;
					else cout<<j<<" "<<i<<endl,bol=1;
				}
			}
		}
	}
	else if(n%4==2&&k==3){
		puts("YES");
		for(int i=4;i<n;i+=4){
			bool bol=0;
			for(int j=i-4+1;j<=i;++j){
				if(j%4!=0&&j%4!=k){
					if(bol)cout<<k+i-4<<" "<<j<<endl;
					else cout<<j<<" "<<i<<endl,bol=1;
				}
			}
		}
		cout<<n-1<<" "<<n<<endl;
	}
	else puts("NO");
}
int main(){
	int T;
	cin>>T;
	while(T--)work();
	return 0;
}