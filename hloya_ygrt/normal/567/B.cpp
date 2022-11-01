#include <iostream>


using namespace std;

bool _in[100][1000000];

int main()
{
    int num,n,cur[100];
    cin>>n;
    char s;
    int prev=0;
    cur[0]=0;for (int j=0;j<100;j++)
    {
        for (int i=0;i<1000000;i++){
            _in[j][i]=false;

        }
        cur[j]=0;
    }

    for (int i=0;i<n;i++){
        cin>>s>>num;
        if(i!=0) cur[i]=cur[i-1];

        if (s=='+'){
            cur[i]++;
            for (int j=i;j<n;j++){
                _in[j][num-1]=true;
            }
        } else
        {
            if (_in[i][num-1]==true) {for (int j=i;j<n;j++){
                _in[j][num-1]=false;

            }cur[i]--;} else{ for (int j=0;j<i;j++){
                cur[j]++;
            } prev++;}
        }
    }int _max=0;
    for (int i=0;i<n;i++){
        if(cur[i]>_max) _max=cur[i];
    }
    if (_max<prev) _max=prev;
    cout<<_max;
    return 0;
}