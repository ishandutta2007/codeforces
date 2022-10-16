#include <algorithm>
#include <iostream>
#include <string>
#include <string.h>
using namespace std;
char t[120][5] = {
"H",
"He",
"Li",
"Be",
"B",
"C",
"N",
"O",
"F",
"Ne",
"Na",
"Mg",
"Al",
"Si",
"P",
"S",
"Cl",
"Ar",
"K",
"Ca",
"Sc",
"Ti",
"V",
"Cr",
"Mn",
"Fe",
"Co",
"Ni",
"Cu",
"Zn",
"Ga",
"Ge",
"As",
"Se",
"Br",
"Kr",
"Rb",
"Sr",
"Y",
"Zr",
"Nb",
"Mo",
"Tc",
"Ru",
"Rh",
"Pd",
"Ag",
"Cd",
"In",
"Sn",
"Sb",
"Te",
"I",
"Xe",
"Cs",
"Ba",
"La",
"Ce",
"Pr",
"Nd",
"Pm",
"Sm",
"Eu",
"Gd",
"Tb",
"Dy",
"Ho",
"Er",
"Tm",
"Yb",
"Lu",
"Hf",
"Ta",
"W",
"Re",
"Os",
"Ir",
"Pt",
"Au",
"Hg",
"Tl",
"Pb",
"Bi",
"Po",
"At",
"Rn",
"Fr",
"Ra",
"Ac",
"Th",
"Pa",
"U",
"Np",
"Pu",
"Am",
"Cm",
"Bk",
"Cf",
"Es",
"Fm",
"Md",
"No",
"Lr",
"Rf",
"Db",
"Sg",
"Bh",
"Hs",
"Mt",
"Ds",
"Rg",
"Cn",
"NH",
"Fl",
"Mc",
"Lv",
"Ts",
"Og" };
int poss[20];
int main()
{
	string s;
	cin >> s;
	int i;
	for (i = 0; i < 118; i++)
	{
		int j;
		for (j = 0; j < 5; j++)
		{
			if (t[i][j] == 0)
				break;
			t[i][j] = toupper(t[i][j]);
		}
	}
	poss[0] = 1;
	for (i = 1; i <= s.size(); i++)
	{
		int j;
		for (j = 0; j < 118; j++)
		{
			if (i >= strlen(t[j]) && poss[i - strlen(t[j])])
			{
				int k;
				int ans = 1;
				for (k = i - strlen(t[j]); k < i; k++)
				{
					if (t[j][k-i+strlen(t[j])] != s[k])
						ans = 0;
				}
				if (ans)
					poss[i] = 1;
			}
		}
	}
	cout << (poss[s.size()] ? "YES" : "NO");
}