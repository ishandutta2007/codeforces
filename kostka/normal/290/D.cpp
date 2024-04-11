#include<iostream>

using namespace std;

int liczba(char a)
{
    if('A'<=a && a<='Z')
        return a-'A';
    if('a'<=a && a<='z')
        return a-'a';
}

int main()
{
    string x;
    cin >> x;
    int n;
    cin >> n;
    for(int i=0; x[i]; i++)
    {
        int a = liczba(x[i]);
        if(a < n)
            cout << char(a+'A');
        else
            cout << char(a+'a');
    }
}