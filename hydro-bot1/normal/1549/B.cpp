// Hydro submission #633031ae052eccf9f575a355@1664102830846
#include<bits/stdc++.h>

using namespace std;

const int N=2e5+10;
int a[N];
int b[N];

int Pd[5]={1,0,1};

void change(string s,int num[]){
	int len=s.size();
	for(int i=0;i<len;i++){
		num[i+1]=s[i]-'0'; 
	}
}

void print(){
	for(int i=1;i<=5;i++){
		printf("%d ",a[i]);
	}
	printf("\n\n");
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		string s1,s2;
		cin>>s1>>s2; 
		change(s1,a);
		change(s2,b);
		
		int ans=0;
		for(int i=1;i<=n;i++){
			int index=0;
			if(b[i]==0){
				continue;
			}
			for(int j=i-1;j<=i+1;j++){
				if(a[j]==Pd[index]){
					a[j]=2;
					ans++;
					break;
				}
				index++;
			}			
		}
		printf("%d\n",ans);
		for(int i=1;i<=n;i++){
			a[i]=0;
		}
		for(int i=1;i<=n;i++){
			b[i]=0;
		}
	}
	
	return 0;
}