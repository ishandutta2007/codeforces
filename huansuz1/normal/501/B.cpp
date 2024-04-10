 #include <conio.h> 
 #include <iostream> 
 #include <math.h> 
 #include <map>
 using namespace std;
	
string s[1234],l[1234],ss[1234],dd[1234];
map<string ,string> a,b;	
int q,z;
 int main()   {
 	cin>>q;
 	for (int i=0; i<q; i++)  
 		cin>>s[i]>>l[i];
 	
 	for (int i=0; i<q; i++){
 		if (s[i]!="")  {
 			string y=l[i];
 			for (int j=i; j<q; j++)
 				if (s[j]==y) {y=l[j]; s[j]="";}	
 			l[i]=y;
 			ss[z]=s[i]; dd[z]=y;
 			z++;
 		}
 	}	
 	cout<<z<<endl;
 	for (int i=0; i<z; i++)
 		cout<<ss[i]<<" "<<dd[i]<<endl;


	
	return 0;
 }