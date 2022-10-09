t = int(input())
for _ in range(t):
    n = int(input())
    s = input()
    a = 'YES'
    for u in s.split('W'):
        if u == '' or (('R' in u) and ('B' in u)):
            pass
        else:
            a = 'NO'
    print(a)