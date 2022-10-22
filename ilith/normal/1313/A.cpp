#include<bits/stdc++.h>
using namespace std;
int n;
int a,b,c;
int t[20][4]={{1,0,0},{0,1,0},{0,0,1},{1,1,0},{1,0,1},{0,1,1},{1,1,1}}; 
int main(){
	cin>>n;
	while(n--){
		int mi=0;
		cin>>a>>b>>c;
		for(int i=0;i<(1<<7);i++){
			int aa=0,bb=0,cc=0;
			int ans=0;
			for(int j=0;j<=7;j++){
				if(i&(1<<j)){
					aa+=t[j][0];
					bb+=t[j][1];
					cc+=t[j][2];
					ans++;
				}
			}
			if(aa<=a&&bb<=b&&cc<=c&&mi<ans)mi=ans;
		}
		cout<<mi<<'\n';
	}
	return 0;
}