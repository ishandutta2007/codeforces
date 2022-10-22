#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
long a,b,u=1;

cin>>a>>b;
while(true)
{a-=u;
u++;
if(a<0){cout<<"Vladik";return 0;}
b-=u;
u++;
if(b<0){cout<<"Valera";return 0;}

}
    return 0;
}