s=input()
for i in range(5,0,-1):
    if (len(s)+i-1)//i<=20:
        x=i
print(x,(len(s)+x-1)//x)
a=''
for i in range(x):
    a+=s[:len(s)//x]+((len(s)-1)//x+1-len(s)//x)*'*'+'\n'
    s=s[len(s)//x:]
    x-=1
print(a)