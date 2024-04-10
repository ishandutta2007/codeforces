s = input().strip()
acnt = s.count('a')
len = len(s)
print(min(acnt*2-1,len))