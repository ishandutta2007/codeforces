#include<bits/stdc++.h>
using namespace std;
bool tab[1000005];
bool tab2[1000005];
long long licz,licz2,zero;
bool check(int a,int b)
{
    for(int x=1;x<=a;x++)
        for(int y=1;y<=b;y++)
            if((4*x+9*y)%49==0)
                return true;
    for(int x=1;x<=b;x++)
    {
        for(int y=1;y==y;y++)
        {
            if(49*y>9*x)
                break;
            if((9*x-49*y)%4==0)
                return true;
        }

    }
    return false;

}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    long long a;
    cin>>a;
    for(int x=0;x<9;x++)
        for(int y=0;y<49;y++)
        {
            if(check(x,y)==true)
                break;
            licz+=max(zero,a-x-y+1);
        }
    cout<<licz;
	return 0;
}