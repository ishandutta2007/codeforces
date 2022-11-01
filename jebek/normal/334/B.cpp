#include <iostream>
#include<algorithm>

using namespace std;

int a[8],b[8],x1,x2,x3,y1,y2,y3;

int main()
{
    for(int i=0;i<8;i++){
        cin>>a[i]>>b[i];
        for(int j=0;j<i;j++)
            if(a[i]==a[j]&& b[i]==b[j])
            {
                cout<<"ugly";
                return 0;
            }
    }
    sort(a,a+8);
    sort(b,b+8);
    for(int i=0;i<8;i++)
    {
        if(a[i]==a[0])
            x1++;
        if(a[i]==a[3])
            x2++;
        if(a[i]==a[5])
            x3++;
        if(b[i]==b[0])
            y1++;
        if(b[i]==b[3])
            y2++;
        if(b[i]==b[5])
            y3++;
    }
    if(a[0]==a[3] || a[0]==a[5] || a[3]==a[5] || x1!=3 || x2!=2 || x3!=3 || b[0]==b[3] || b[0]==b[5] || b[3]==b[5] || y1!=3 || y2!=2 || y3!=3)
    {
        cout<<"ugly";
        return 0;
    }
    cout<<"respectable";
    return 0;

}