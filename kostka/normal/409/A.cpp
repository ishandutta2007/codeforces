#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
  string a, b;
  int la = 0, lb = 0;
  cin >> a >> b;
  for(int i=0; a[i]; i+=2)
  {
    if(a[i]=='(' && b[i]=='[')
      lb++;
    if(a[i]=='[' && b[i]=='8')
      lb++;
    if(a[i]=='8' && b[i]=='(')
      lb++;
    if(b[i]=='(' && a[i]=='[')
      la++;
    if(b[i]=='[' && a[i]=='8')
      la++;
    if(b[i]=='8' && a[i]=='(')
      la++;
  }
  if(la>lb)
    cout << "TEAM 1 WINS";
  if(la<lb)
    cout << "TEAM 2 WINS";
  if(la==lb)
    cout << "TIE";
  return 0;
}