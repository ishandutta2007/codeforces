import datetime

d = datetime.date(2016, 1, 1)
v = input().split()

ans = 0

while True:
    if d.year != 2016:
        break
    if v[2] == 'week' and int(v[0]) == d.isoweekday():
        ans += 1
    if v[2] == 'month' and int(v[0]) == d.day:
        ans += 1
    d = d + datetime.timedelta(days=1)

print(ans)