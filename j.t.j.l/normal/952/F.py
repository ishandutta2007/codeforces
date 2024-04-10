s = input()
now = 0
n = len(s)
ans = []
while (now < n) and (s[now] != '-') and (s[now] != '+'):
    ans.append(ord(s[now])-48)
    now += 1
ans.reverse()
while now < n:
    opt = s[now]
    now += 1
    a = [ord(opt)-48]
    while (now < n) and (s[now] != '-') and (s[now] != '+'):
        a.append(ord(s[now])-48)
        now += 1
    a.reverse()
    if len(a) <= len(ans):
        for i in range(len(ans) - len(a)):
            a.append(0)
    else:
        for i in range(len(a) - len(ans)):
            ans.append(0)
    for i in range(len(ans)):
        if opt == '-':
            ans[i] -= a[i]
        else:
            ans[i] += a[i]
ret = 0
ans.reverse()
for i in range(len(ans)):
    ret = ret * 10 + ans[i]
print(ret)