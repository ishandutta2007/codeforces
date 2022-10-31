#include <iostream>
#include <string>
using namespace std;
int a=0,b=0,c=0,d=0;
string s;
int main(){
 cin >> s;

for (int i=0; i<s.length(); i++){
	if (s[i]=='H') a++;
	if (s[i]=='Q') b++;
	if (s[i]=='9') c++;
	if (s[i]=='+') d++;
}
if ((a>=1||b>=1||c>=1)) cout<<"YES"; else cout<<"NO";




}