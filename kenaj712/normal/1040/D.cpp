#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	srand((int)time(0));
    long long a,b,jedynka=1;
    cin>>a>>b;
    long long pocz=1,kon=a;
    string slowo;
    while(0==0)
    {
        if(kon-pocz>4*b+10)
        {
            cout<<pocz<<" "<<(kon+pocz)/2<<'\n';
            cout.flush();
            cin>>slowo;
            if(slowo=="Yes")
                kon=(pocz+kon)/2;
            else
                pocz=(pocz+kon)/2+1;

            pocz=max(jedynka,pocz-b);
            kon=min(a,kon+b);

        }
        else
        {
           // cout<<pocz<<" "<<kon<<'\n';
            unsigned long long random=rand()%(kon-pocz+1);
            while(random>kon-pocz+1)
                random=rand()%(kon-pocz+1);
            cout<<pocz+random<<" "<<pocz+random<<'\n';
            cout.flush();
            cin>>slowo;
            if(slowo=="Yes")
                return 0;
            pocz=max(jedynka,pocz-b);
            kon=min(a,kon+b);
        }


    }
	return 0;
}