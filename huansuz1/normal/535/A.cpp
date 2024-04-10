 #include <conio.h> 
 #include <iostream> 
 #include <math.h> 
 #include <map>
 using namespace std;

string s,l[12],a[12];	
 int main()   {
   cin>>s;
   l[0]= "zero";
   l[1]= "one";
   l[2]= "two";
l[3]= "three";
l[4]= "four";
l[5]= "five";
l[6]= "six";
l[7]= "seven";
l[8]= "eight";
l[9]= "nine";
 a[1]="ten";
 a[2]="twenty";
 a[3]="thirty";
 a[4]="forty";
 a[5]="fifty";
 a[6]="sixty";
 a[7]="seventy";
 a[8]="eighty";
 a[9]="ninety";


   if (s.length()==1) {
   	cout<<l[s[0]-'0'];
   }else {
   if (s[1]=='0') cout<<a[s[0]-'0']; else 
   if (s[0]=='1'&& s[1]=='5') {cout<<"fifteen";} else
   if (s[0]=='1'&& s[1]=='1') {cout<<"eleven";} else
   if (s[0]=='1'&& s[1]=='2') {cout<<"twelve";} else
   if (s[0]=='1'&& s[1]=='3') {cout<<"thirteen";} else
   if (s[0]=='1'&& s[1]=='8') {cout<<"eighteen";} else
   
   if (s[0]=='1') cout<<l[s[1]-'0']<<"teen"; else
   cout<<a[s[0]-'0']<<"-"<<l[s[1]-'0'];      
    }
	
	return 0;
 }