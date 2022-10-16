#include <iostream>

using namespace std;

int n, l, r, x;
int sol;
int c[20];

int main()
{
    cin>>n>>l>>r>>x;

    for(int i=1;i<=n;i++)
        cin>>c[i];

    for(int i=0;i<(1<<n);i++)
    {
        int m=1000000005;
        int M=0;
        int sum=0;

        for(int j=0;j<n;j++)
        {
            if((i&(1<<j))==(1<<j)){
                if(c[j+1]<m)
                    m=c[j+1];

                if(c[j+1]>M)
                    M=c[j+1];

                sum+=c[j+1];
            }
        }

            if((M-m)>=x && l<=sum && r>=sum)
                sol++;
    }

    cout<<sol<<'\n';


    return 0;
}