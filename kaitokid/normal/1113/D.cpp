#include <iostream>

using namespace std;
string s ;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
cin>>s;
bool bl=true;
for(int i=1;i<((int)s.size())/2;i++)if(s[i]!=s[i-1])bl=false;
if(bl){cout<< "Impossible" ;return 0;}
int n=s.size();
for(int i=1;i<n;i++)
{
    bool pal=true;
    bool eq=true;
    for(int j=0;j<n;j++){if(s[(i+j)%n]!=s[(i-1-j+n)%n]){pal=false;break;}
    if(s[(i+j)%n]!=s[j])eq=false;     }
        if((!eq)&&pal){cout<<1;return 0;}

}
cout<<2;
    return 0;
}