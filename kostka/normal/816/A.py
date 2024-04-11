def minutes(time):
    return int(time[:2])*60 + int(time[3:])
    
def zeroes(x):
    sx = str(x)
    if len(sx) == 1:
        sx = "0"+sx
    return sx

def format(minutes):
    hours = minutes//60
    minutes = minutes%60
    return zeroes(hours)+":"+zeroes(minutes)
    
def palindrome(x):
    return x == x[::-1]

s = minutes(input())
for i in range(24*60):
    if palindrome(format((s + i)%(24*60))):
        print(i)
        break