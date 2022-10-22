#include <iostream>
using namespace std;

int main() {
	// your code goes here
    long n,i;
    long long x;
    cin>>n;
    for(i=0;i<n;i++){
    cin>>x;
    if(x%4==0)cout<<x/4<<endl;
    else if(x%4==1){
    if(x<9)cout<<-1<<endl;
    else cout<<(x-9)/4+1<<endl;
    }
else if(x%4==2){
    if(x<6)cout<<-1<<endl;
    else cout<<(x-6)/4+1<<endl;
    }
else if(x%4==3){
    if(x<15)cout<<-1<<endl;
    else cout<<(x-15)/4+2<<endl;
}}
	return 0;
}