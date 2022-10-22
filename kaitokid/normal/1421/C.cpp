#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
string s;
int main()
{ios::sync_with_stdio(0);
cin>>s;
cout<<3<<endl;
int n=s.size();
cout<<"L 2"<<endl;
n++;
cout<<"R 2"<<endl;
n+=(n-2);
cout<<"R "<<n-1<<endl;
    return 0;
}