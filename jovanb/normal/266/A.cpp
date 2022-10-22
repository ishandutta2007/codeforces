#include <iostream>
using namespace std;
char ch[10000];
int main() {
	// your code goes here
int k;
cin>>k;
    cin>>ch;
int br=0;
    for(int i=1;i<k;i++){
        if(ch[i]==ch[i-1])br++;
}
cout<<br;
	return 0;
}