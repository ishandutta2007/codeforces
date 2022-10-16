#include<iostream>
using namespace std;
bool ball[3];
int main(){
	long long n;
	int f,six;
	cin>>n>>f;
	six=n%6;
	ball[f]=true;
	for(six;six>=1;six--){
		if(six%2==0&&ball[0]==false){
			ball[1]=!ball[1];
			ball[2]=!ball[2];
		}
		if(six%2==1&&ball[2]==false){
			ball[0]=!ball[0];
			ball[1]=!ball[1];
		}
	}
	for(int i=0;i<=2;i++){
		if (ball[i]==true)cout<<i<<endl;
	}
	return 0;
}