#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    int t;
    int cnt = 0;
    for(int i = 0; i < n ; i++)
    {
        scanf("%d",&t);
        if(t==1)
        {
            cnt++;
        }
    }
    if(cnt>=1)
    {
        cout<<"HARD"<<endl;
    }
    else{
        cout<<"EASY"<<endl;
    }
    return 0;
}