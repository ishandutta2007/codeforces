def decalpha(a):
    f=''
    while a:
        f=chr((a-1)%26+ord("A"))+f
        a=(a-1)//26
    return f
def alphadec(a):
    f=0
    a=a[::-1]
    for i in range(len(a)):
        f+=26**i*(ord(a[i])-ord("A")+1)
    return f
n=int(input())
for i in range(n):
    s=input()
    f=1
    if s[0]=="R" and "C" in s:
        x=s.index("C")
        g=s[1:x]
        try:
            g=int(g)
            h=decalpha(int(s[x+1:]))
            print(h+str(g))
            f=0
        except:
            f=1
    if f:
        i=1
        while not '0'<=s[i]<='9':
            i+=1
        print("R"+s[i:]+"C"+str(alphadec(s[:i])))