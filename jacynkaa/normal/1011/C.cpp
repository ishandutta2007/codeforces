#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define mp make
#define double long double

vector <double> ladowania;
vector <double> starty;
double masa;
int n;
//long double zero=0.000000000;

bool sprawdzanie (double paliwo)
{
    for (int i=0; i<n; i++)
    {
  //  cout <<paliwo<<endl;

        double zuzycie=(paliwo+masa)/starty[i];
       // cout <<zuzycie<<endl;

        if(zuzycie>paliwo)
            return false;

        paliwo=paliwo-zuzycie;

      //  cout <<paliwo<<endl;

        zuzycie=(paliwo+masa)/ladowania[i];
     //    cout <<zuzycie<<endl;

        if(zuzycie>paliwo)
            return false;

        paliwo=paliwo-zuzycie;
    }
    return true;
}

void wczytywanie ()
{
    cin>>n>>masa;
  //  cout <<masa<<endl;
    ladowania.resize(n);
    starty.resize(n);

    for (int i=0; i<n; i++)
        cin>>starty[i];

    for (int i=1; i<=n; i++)
        cin>>ladowania[(i+1)%n];
}


main()
{

cout.setf( ios::fixed );
cout.precision(10);

    wczytywanie();

    if(sprawdzanie(2e9)==false)
    {
        cout<<-1<<endl;
    }

    else
    {
        double p=0;
        double q=1e9+5;

        for (int i=0; i<200; i++)
        {
            double s=(p+q)/2;

            if(sprawdzanie(s)==true)
                q=s;
            else
                p=s;
        }
        cout<<p<<endl;
    }
}