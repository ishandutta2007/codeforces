for i in range(int(input())):
    s=input()
    if s==s[0]*len(s):
        print(-1)
    else:
        i=''
        for e in sorted(s):
            i+=e
        print(i)