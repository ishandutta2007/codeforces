#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
long long matrix1[205][205];
long long matrix2[205][205];
long long matrix3[205][205];
void mnoz12(int b)
{
    for(int x=0;x<b;x++)
        for(int y=0;y<b;y++)
            for(int z=0;z<b;z++)
                matrix3[x][y]=(matrix3[x][y]+matrix1[x][z]*matrix2[z][y])%mod;
    for(int x=0;x<b;x++)
        for(int y=0;y<b;y++)
        {
            matrix2[x][y]=matrix3[x][y];
            matrix3[x][y]=0;
        }

}
void mnoz11(int b)
{
    for(int x=0;x<b;x++)
        for(int y=0;y<b;y++)
            for(int z=0;z<b;z++)
                matrix3[x][y]=(matrix3[x][y]+matrix1[x][z]*matrix1[z][y])%mod;
        for(int x=0;x<b;x++)
            for(int y=0;y<b;y++)
        {
            matrix1[x][y]=matrix3[x][y];
            matrix3[x][y]=0;
        }
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	long long a,b;
	cin>>a>>b;
	matrix1[0][0]=1;
	matrix1[0][b-1]=1;
    for(int x=1;x<b;x++)
        matrix1[x][x-1]=1;
    for(int x=0;x<b;x++)
        matrix2[x][x]=1;
    while(a!=0)
    {
        if(a%2==1)
            mnoz12(b);
        mnoz11(b);
        a/=2;
    }
    for(int x=0;x<b;x++)
        for(int y=0;y<b;y++)
    {
        if(x+y<b)
            matrix1[x][y]=1;
        else
            matrix1[x][y]=0;
    }
    mnoz12(b);
    cout<<matrix2[0][1];
    /*for(int x=0;x<b;x++)
    {
        for(int y=0;y<b;y++)
            cout<<matrix2[x][y]<<" ";
        cout<<'\n';
    }*/
	return 0;
}