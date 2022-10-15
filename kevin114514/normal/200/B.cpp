#include<bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    cin>>N;
    int Cnt=0;
    for(int i=0;i<N;i++)
    {
        int X;
        cin>>X;
        Cnt+=X;
    }
    printf("%.12lf\n",Cnt*1.0/N);
    return 0;
}