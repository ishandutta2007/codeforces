s=input()
n=int(s)
a=len(s)*'0'
f=-1
while int(a)<=n:
    x=a.rfind('0')
    a=a[:x]+'1'+'0'*(len(a)-x-1)
    f+=1
print(f)