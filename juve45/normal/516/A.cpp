#include <iostream>

using namespace std;

int n, nr[12];

int main()
{
char c;
    cin>>n;
for(int i=1;i<=n;i++)
{
    cin>>c;
    int a=c-'0';
    if(a<=1) continue;
    else{
        if(a==2 || a==3 || a==5 || a==7)
            nr[a]++;
        if(a==4)
        {
            nr[2]++;
            nr[2]++;
            nr[3]++;
        }
        if(a==6)
        {
            nr[5]++;
            nr[3]++;
        }
        if(a==8){
                nr[7]++;
                nr[2]++;
                nr[2]++;
                nr[2]++;
        }
        if(a==9){
            nr[7]++;
            nr[3]++;
            nr[3]++;
            nr[2]++;
        }


    }

}
    for(int i=9;i>1;i--)
        for(int j=1;j<=nr[i];j++)
        cout<<i;

        return 0;
}