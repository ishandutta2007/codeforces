s=list(input())
if not '[' in s or not ']' in s:
    print(-1)
else:
    a=s.index('[')
    s.reverse()
    b=len(s)-s.index(']')-1
    s.reverse()
    s=s[a:b+1]
    if s.count(':')<2:
        print(-1)
    else:
        a=s.index(':')
        s.reverse()
        b=len(s)-s.index(':')-1
        s.reverse()
        d=s[a:b+1]
        print(d.count('|')+4)