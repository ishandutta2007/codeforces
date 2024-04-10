## This is a solution for problem make-planes
#  This is nk_ok.py
#
#  @author: Nikolay Kalinin
#  @date: Mon, 23 Apr 2018 16:28:50 +0300

k, n, s, p = map(int, input().split())
sheets_per_person = (n + s - 1) // s
sheets = k * sheets_per_person
print((sheets + p - 1) // p)