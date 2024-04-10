#include <iostream>
#include<string>

using namespace std;

string s[]={"|#.#.#.#.#.#.#.#.#.#.#.|D|)","|#.#.#.#.#.#.#.#.#.#.#.|.|","|#.#.#.#.#.#.#.#.#.#.#.|.|)","|#.......................|"};
int n;

int main()
{
    cin>>n;
    cout<<"+------------------------+"<<endl;
    if(n>=3)
    {
        n--;
        s[3][1]='O';
    }
    for(int i=0;i<n;i++)
        s[i%3][i/3*2+1]='O';
    cout<<s[0]<<endl<<s[1]<<endl<<s[3]<<endl<<s[2]<<endl<<"+------------------------+"<<endl;
}