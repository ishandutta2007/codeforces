#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        bool f[2]={false,false};
        while(N--)
        {
            int X;
            cin>>X;
            f[X%2]=true;
        }
        if(f[0]&&!f[1]||f[1]&&!f[0])
            puts("YES");
        else    puts("NO");
    }
    return 0;
}