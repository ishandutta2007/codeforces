#include <iostream>


using namespace std;


int main()
{
    int n;
    int ti[100];
    int k;
    int o,tk=-1;
    int er;
    o=0;
    cin>>n;
    for (k=0;k<n;k++)
    cin>>ti[k];
    while (tk!=0) {

        er=0;

        for (k=1;k<n;k++)

             if (ti[k]>=ti[er]) er=k;
        if (er==0) tk=0; else
        {
            ti[er]--;ti[0]++;
            o++;
        }

    }
    
    cout<<o;
    return 0;
}