s=input()
k=int(input())
n=len(s)-s.count('?')-s.count("*")
if n<k:
    if not "*" in s:
        print("Impossible")
    else:
        x=s.index("*")
        f=k-n
        s=s[:x]+s[x-1]*f+s[x:]
        while '*' in s:
            s=s[:s.index("*")]+s[s.index("*")+1:]
        while "?" in s:
            s=s[:s.index("?")]+s[s.index("?")+1:]
        print(s)
elif n>k:
    f=n-k
    if s.count("?")+s.count("*")<f:
        print("Impossible")
    else:
        b=s.count("?")
        for i in range(min(f,b)):
            s=s[:s.index("?")-1]+s[s.index("?")+1:]
        for i in range(f-min(f,b)):
            s=s[:s.index("*")-1]+s[s.index("*")+1:]
        while '*' in s:
            s=s[:s.index("*")]+s[s.index("*")+1:]
        while "?" in s:
            s=s[:s.index("?")]+s[s.index("?")+1:]
        print(s)
else:
    while '*' in s:
        s=s[:s.index("*")]+s[s.index("*")+1:]
    while "?" in s:
        s=s[:s.index("?")]+s[s.index("?")+1:]
    print(s)