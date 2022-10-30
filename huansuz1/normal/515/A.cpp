#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>

using namespace std;

int a,b,c;


int main(){
cin>>a>>b>>c;
a=abs(a);
b=abs(b);
if (c-(a+b)>=0 && (c-(a+b))%2==0) cout<<"Yes"; else cout<<"No";


return 0;
}