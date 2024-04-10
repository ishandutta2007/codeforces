import sys

def ask(n):
    print n
    sys.stdout.flush()
    return raw_input().strip() == 'yes'

# 2: 2 3 5 7 11 13 17 19 23 29 31 37 41 43 47
# 3: 3 5 7 11 13 17 19 23 29 31
# 5: 5 7 11 13 17 19 23
# 7: 11 13

def is_prime(n):
    return n > 1 and all(n % d for d in xrange(2,n))

ps = [p for p in xrange(2,101) if is_prime(p)]

def question():
    for p in ps:
        if p*p <= 100:
            if ask(p):
                for q in ps:
                    if q >= p and p*q <= 100 and ask(p*q):
                        return False
                return True
    return True

print 'prime' if question() else 'composite'