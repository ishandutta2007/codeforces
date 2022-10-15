/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int Police_Strength=0, Event, Crimes_Untreated=0;
    for(int i=1;i<=n;i++)
    {
        cin>>Event;
        if(Event==-1)
        {
            if(Police_Strength==0) Crimes_Untreated++;
            else Police_Strength--;
        }
        else
        {
            Police_Strength+=Event;
        }
    }

    cout<<Crimes_Untreated<<endl;

    return 0;
}