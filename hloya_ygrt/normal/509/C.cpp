#include <bits/stdc++.h>

using namespace std;

    const int maxn=3e3;


    int a[maxn];
    int ans[maxn], prep[maxn];



int main(){

    int n,len;
    scanf("%d", &n);

    for (int i=1;i<=n;i++)
        scanf("%d",a+i);
    len=1;
    ans[1] = 0;
    for(int i=1;i<=n;i++)
        {
             int sum=0;
            int j=0;

        while (1){
            int got = -1;
            j++;
            sum += ans[j];
            for(int k=ans[j]+1;k<10;k++)
                if ((a[i]>=a[i-1]-sum+k)&&(a[i-1]-sum+9*(j-1)+k>=a[i]))
                    {
                        got=k;
                       if (got>0) break;
                    }

            if (got==-1)
                continue;

            memset(prep, 0, sizeof(prep));

            for(int k=j+1;k<=len;k++)
                prep[k]=ans[k];
            prep[j] = got;


            int needsum=a[i]-(got+a[i-1]-sum);
            for(int k=1;k<j;k++)
            {
                prep[k] = min(9, needsum);
                needsum -= prep[k];

            }


            len=max(len,j);
            memset(ans, 0, sizeof(ans));
            for(int k=1;k<=len;k++)
                ans[k] = prep[k];

            for(int k=len;k>0;k--)
                cout<<ans[k];

            sum=needsum;
            cout<<endl;
            break;

        }
    }

return 0;
}