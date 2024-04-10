#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <cstdio>
#include <cmath>      
#include <string>
using namespace std;
int n;
string a[1000],s;

int main(){
cin>>n;
for (int i=0; i<n; i++)
{
cin>>s;
if (s.length()<=10) cout<<s<<endl; else cout<<s[0]<<s.length()-2<<s[s.length()-1]<<endl;

}

return 0;
}