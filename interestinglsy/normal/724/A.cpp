#include <iostream>
using namespace std;

int main(){
	string s1,s2;
	cin >> s1;
	cin >> s2;
	if(s1 == "monday"){
		if(s2 == "monday")cout << "YES\n";//
		if(s2 == "tuesday")cout << "NO\n";//
		if(s2 == "wednesday")cout << "YES\n";//
		if(s2 == "thursday")cout << "YES\n";//
		if(s2 == "friday")cout << "NO\n";
		if(s2 == "saturday")cout << "NO\n";
		if(s2 == "sunday")cout << "NO\n";
	}
	if(s1 == "tuesday"){
		if(s2 == "monday")cout << "NO\n";
		if(s2 == "tuesday")cout << "YES\n";//
		if(s2 == "wednesday")cout << "NO\n";//
		if(s2 == "thursday")cout << "YES\n";//
		if(s2 == "friday")cout << "YES\n";//
		if(s2 == "saturday")cout << "NO\n";
		if(s2 == "sunday")cout << "NO\n";
	}
	if(s1 == "wednesday"){
		if(s2 == "monday")cout << "NO\n";
		if(s2 == "tuesday")cout << "NO\n";
		if(s2 == "wednesday")cout << "YES\n";//
		if(s2 == "thursday")cout << "NO\n";//
		if(s2 == "friday")cout << "YES\n";//
		if(s2 == "saturday")cout << "YES\n";//
		if(s2 == "sunday")cout << "NO\n";
	}
	if(s1 == "thursday"){
		if(s2 == "monday")cout << "NO\n";
		if(s2 == "tuesday")cout << "NO\n";
		if(s2 == "wednesday")cout << "NO\n";
		if(s2 == "thursday")cout << "YES\n";//
		if(s2 == "friday")cout << "NO\n";//
		if(s2 == "saturday")cout << "YES\n";//
		if(s2 == "sunday")cout << "YES\n";//
	}
	if(s1 == "friday"){
		if(s2 == "monday")cout << "YES\n";//
		if(s2 == "tuesday")cout << "NO\n";
		if(s2 == "wednesday")cout << "NO\n";
		if(s2 == "thursday")cout << "NO\n";
		if(s2 == "friday")cout << "YES\n";//
		if(s2 == "saturday")cout << "NO\n";//
		if(s2 == "sunday")cout << "YES\n";//
	}
	if(s1 == "saturday"){
		if(s2 == "monday")cout << "YES\n";//
		if(s2 == "tuesday")cout << "YES\n";//
		if(s2 == "wednesday")cout << "NO\n";
		if(s2 == "thursday")cout << "NO\n";
		if(s2 == "friday")cout << "NO\n";
		if(s2 == "saturday")cout << "YES\n";//
		if(s2 == "sunday")cout << "NO\n";//
	}
	if(s1 == "sunday"){
		if(s2 == "monday")cout << "NO\n";//
		if(s2 == "tuesday")cout << "YES\n";//
		if(s2 == "wednesday")cout << "YES\n";//
		if(s2 == "thursday")cout << "NO\n";
		if(s2 == "friday")cout << "NO\n";
		if(s2 == "saturday")cout << "NO\n";
		if(s2 == "sunday")cout << "YES\n";//
	}
	return 0;
}