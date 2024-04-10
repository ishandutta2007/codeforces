#include<bits/stdc++.h>
using namespace std;
char ch[100010];
int q1=1;
int main(){
	cin>>ch;
	int k=strlen(ch);
	for(int i=1;i<k;i++){
		if(ch[i]=='0')q1=0;
	}
	if(q1){
		for(int i=1;i<k;i++){
			cout<<ch[i];
		}
	}
	else {
		bool fl=1;
		for(int i=0;i<k;i++){
			if(ch[i]=='0'&&fl==1){
				fl=0;
				continue;
			}
			cout<<ch[i];
		}
	}
	return 0;
}