#include<iostream>
using namespace std;
int main(){
	string s;
	cin>>s;
	int x=0,y=0;
	for(int i=0;i<s.size()-1;i++)
	{
		y=0;
		if(x==0 && s[i]=='a' && s[i+1]=='t' && i!=0 && i<s.size()-2){
			cout<<'@';
			i+=1;
			x=1;
			y=1;
		}
		if(s[i]=='d' && s[i+1]=='o' && s[i+2]=='t' && i!=s.size()-3 && i!=s.size()-2 && i!=0 && y==0){
			cout<<'.';
			y=1;
			i+=2;
		}
		if(y==0)
		{
			cout<<s[i];
		}
	}
	cout<<s[s.size()-1];
}