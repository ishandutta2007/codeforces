#include<iostream>
#include<vector>
using namespace std;
long long int liczbunia (vector <long long int> &cyfry, int baza)
{
    long long int liczba=0;

    for (int i=0;i<cyfry.size(); i++)
    {
        liczba=liczba*baza+cyfry[i];

    }

    return liczba;



}


main()
{ int n;
cin >> n;

    vector <long long int> cyfry (n);
    int baza;
    cin >> baza;
    for (int i=0; i<n; i++)
        cin >>cyfry[i];
  long long int x= liczbunia(cyfry, baza);


 int k;
cin >> k;

    vector <long long int> cyferki (k);
    int baza2;
    cin >> baza2;
    for (int i=0; i<k; i++)
        cin >>cyferki[i];
  long long int y= liczbunia(cyferki, baza2);


if(x>y)
    cout << ">"<<endl;
if(x<y)
    cout << "<"<<endl;
    if (x==y)
    cout << "=" <<endl;

}