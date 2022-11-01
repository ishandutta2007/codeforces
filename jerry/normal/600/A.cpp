#include <bits/stdc++.h>
using namespace std;

vector<string> nums, words;
char s[100005];

void f(string tmp)
{
	if (tmp.size() == 0) words.push_back(tmp);
	else if (tmp[0]=='0'&&tmp.size()>1) words.push_back(tmp);
	else if (tmp[0]=='0') nums.push_back(tmp);
	else
	{
		bool num = true;
		for (char x: tmp) if (x < '0' || x > '9')
		{
			num = false;
			break;
		}
		if (num) nums.push_back(tmp);
		else words.push_back(tmp);
	}
}

int main()
{
	scanf("%s", s);
	string tmp;
	for (unsigned i = 0;s[i];i++)
		if (s[i] == ',' || s[i] == ';')
		{
			f(tmp);
			tmp = "";
		} else
			tmp.push_back(s[i]);
	f(tmp);
	for (unsigned i = 0;i < nums.size();i++) printf("%c%s", i?',':'\"', nums[i].c_str()); printf("%c\n", nums.size()?'\"':'-');
	for (unsigned i = 0;i < words.size();i++) printf("%c%s", i?',':'\"', words[i].c_str()); printf("%c\n", words.size()?'\"':'-');
}