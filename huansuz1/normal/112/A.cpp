#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
string s,l;
int z=0;
int main(){
	cin >> s >> l;
	for (int i=0; i<s.length(); i++){
		if ((s[i]>='A') &&(s[i] <= 'Z' )) s[i] = s[i] -'A' + 'a';
		if ((l[i]>='A') &&(l[i] <= 'Z' )) l[i] = l[i] -'A' + 'a';
}
	if (l==s) cout<<0; else 
	if (s>l) cout<<1; else cout<<-1;
	

}